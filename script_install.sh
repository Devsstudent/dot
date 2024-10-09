#!/bin/sh


# Next improve is to add a variable that will take MAC or LINUX to know which config to run
sudo apt update -y && sudo apt-updrade -y
sudo apt install -y vim bash-completion fzf

git clone https://github.com/4ndv/bash-suggest.git ~/.bash-suggest

curl -sS https://starship.rs/install.sh | sh

mkdir -p ~/.config && touch ~/.config/starship.toml
git clone --depth 1 https://github.com/junegunn/fzf.git ~/.fzf
~/.fzf/install
