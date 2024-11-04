-- Keymaps are automatically loaded on the VeryLazy event
-- Default keymaps that are always set: https://github.com/LazyVim/LazyVim/blob/main/lua/lazyvim/config/keymaps.lua
-- Add any additional keymaps here
local map = vim.keymap.set

map("n", "T", ":Neotree toggle<CR>", { noremap = true, silent = true })

----Tab Management
---- Create global variables to store the last and current tab
--_G.last_tab = nil
--_G.current_tab = nil
--
---- Function to update tab history
--local function update_tab_history()
--    _G.last_tab = _G.current_tab
--    _G.current_tab = vim.api.nvim_get_current_tabpage()
--end
--
---- Function to toggle between the last used and current tab
--local function toggle_tab()
--    if _G.last_tab and vim.api.nvim_tabpage_is_valid(_G.last_tab) then
--        -- If last_tab exists and is a valid tab, switch to it
--        vim.api.nvim_set_current_tabpage(_G.last_tab)
--        -- Swap last and current to allow toggling back
--        _G.last_tab, _G.current_tab = _G.current_tab, _G.last_tab
--    end
--end
--
---- Setup autocommand to track tab switches
--vim.api.nvim_create_autocmd("TabEnter", {
--    callback = update_tab_history,
--})

-- Map Ctrl-p to toggle between last and current tab
--map("n", "<C-p>", toggle_tab, { noremap = true, silent = true })
map("n", "<C-b>", ":bprev<CR>", { noremap = true, silent = true }) -- Ctrl-b for previous tab
map("n", "<C-n>", ":bnext<CR>", { noremap = true, silent = true })
