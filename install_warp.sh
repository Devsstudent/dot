#!/bin/bash

# Define source and target paths
DOT_DIR="$HOME/dot/warp"
MACOS_CONFIG="$HOME/Library/Application Support/dev.warp.Warp"
LINUX_CONFIG="$HOME/.config/warp-terminal/"
LINUX_THEMES="$HOME/.local/share/warp-terminal/themes"

# Colors for output
GREEN='\033[0;32m'
BLUE='\033[0;34m'
RED='\033[0;31m'
NC='\033[0m' # No Color

# Create required directories
create_directories() {
  echo -e "${BLUE}Creating necessary directories...${NC}"
  mkdir -p "$DOT_DIR"/{themes,config}

  # Create OS-specific directories
  if [[ "$OSTYPE" == "darwin"* ]]; then
    mkdir -p "$MACOS_CONFIG/themes"
  else
    mkdir -p "$LINUX_CONFIG"
    mkdir -p "$LINUX_THEMES"
  fi
}

# Install Warp based on OS
install_warp() {
  if [[ "$OSTYPE" == "darwin"* ]]; then
    echo -e "${BLUE}Installing Warp on macOS...${NC}"
    if ! command -v brew &>/dev/null; then
      echo -e "${RED}Homebrew not found. Please install Homebrew first.${NC}"
      exit 1
    fi
    brew install --cask warp
  elif [[ -f /etc/fedora-release ]]; then
    echo -e "${BLUE}Installing Warp on Fedora...${NC}"
    sudo rpm --import https://app.warp.dev/signing.key
    sudo curl -Lo /etc/yum.repos.d/warp.repo https://app.warp.dev/yum/warp.repo
    sudo dnf install warp-terminal -y
  elif [[ "$OSTYPE" == "linux-gnu"* ]]; then
    if [[ ! -f "~/.config/warp-terminal/" ]]; then
      echo -e "${BLUE}Warp already installed...${NC}"
    else
      echo -e "${BLUE}Installing Warp on Linux...${NC}"
      sudo dpkg -i ./warp/warp.deb
    fi
  else
    echo -e "${RED}Unsupported operating system${NC}"
    exit 1
  fi
}

# Link configurations based on OS
link_configs() {
  echo -e "${BLUE}Linking configurations...${NC}"

  if [[ "$OSTYPE" == "darwin"* ]]; then
    # macOS linking
    if [ -d "$MACOS_CONFIG" ]; then
      # Backup existing config if it exists
      if [ -d "$MACOS_CONFIG.backup" ]; then
        rm -rf "$MACOS_CONFIG.backup"
      fi
      mv "$MACOS_CONFIG" "$MACOS_CONFIG.backup"
    fi
    ln -sfn "$DOT_DIR/config" "$MACOS_CONFIG"
  else
    # Linux linking
    if [ -d "$LINUX_CONFIG" ]; then
      # Backup existing config if it exists
      if [ -d "$LINUX_CONFIG.backup" ]; then
        rm -rf "$LINUX_CONFIG.backup"
      fi
      mv "$LINUX_CONFIG" "$LINUX_CONFIG.backup"
    fi
    ln -sfn "$DOT_DIR/config" "$LINUX_CONFIG"
  fi
}

# Copy themes to appropriate location
install_themes() {
  echo -e "${BLUE}Installing themes...${NC}"
  local theme_dir

  if [[ "$OSTYPE" == "darwin"* ]]; then
    theme_dir="$MACOS_CONFIG/themes"
  else
    theme_dir="$LINUX_THEMES"
  fi

  # Backup existing themes if they exist
  if [ -d "$theme_dir" ]; then
    if [ -d "$theme_dir.backup" ]; then
      rm -rf "$theme_dir.backup"
    fi
    mv "$theme_dir" "$theme_dir.backup"
  fi

  mkdir -p "$theme_dir"
  cp -r "$DOT_DIR/themes/"* "$theme_dir/"
  echo -e "${GREEN}Themes installed successfully${NC}"
}

# Main setup function
setup() {
  echo -e "${BLUE}Starting Warp setup...${NC}"

  # Check if Warp is installed
  install_warp

  create_directories
  link_configs
  install_themes

  echo -e "${GREEN}Setup complete! Please restart Warp to apply changes.${NC}"
}

# Function to save current config to dot directory
save_current_config() {
  echo -e "${BLUE}Saving current configuration to ~/dot/warp...${NC}"

  # Determine current config and theme paths
  local current_config
  local current_themes
  if [[ "$OSTYPE" == "darwin"* ]]; then
    current_config="$MACOS_CONFIG"
    current_themes="$MACOS_CONFIG/themes"
  else
    current_config="$LINUX_CONFIG"
    current_themes="$LINUX_THEMES"
  fi

  # Save configs (excluding themes directory if it exists)
  rsync -av --exclude='themes' "$current_config/" "$DOT_DIR/config/"

  # Save themes
  if [ -d "$current_themes" ] && [ "$(ls -A "$current_themes")" ]; then
    mkdir -p "$DOT_DIR/themes"
    rsync -av "$current_themes/" "$DOT_DIR/themes/"
  fi

  echo -e "${GREEN}Current configuration saved successfully${NC}"
}

# Show help menu
show_help() {
  echo "Warp Configuration Manager"
  echo "Usage: $0 [option]"
  echo "Options:"
  echo "  setup    - Install Warp and set up configurations"
  echo "  save     - Save current configuration to ~/dot/warp"
  echo "  help     - Show this help message"
}

# Main script
case "$1" in
"setup")
  setup
  ;;
"save")
  save_current_config
  ;;
"help" | "")
  show_help
  ;;
*)
  echo -e "${RED}Invalid option. Use 'help' to see available options.${NC}"
  exit 1
  ;;
esac
