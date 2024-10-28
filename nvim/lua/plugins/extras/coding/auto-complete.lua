return {
    "hrsh7th/nvim-cmp",
    ---@param opts cmp.ConfigSchema
    opts = function(_, opts)
        local cmp = require("cmp")

        opts.mapping = vim.tbl_extend("force", opts.mapping, {
            ["<Tab>"] = cmp.mapping(function(fallback)
                if cmp.visible() then
                    -- You could replace select_next_item() with confirm({ select = true }) to get VS Code autocompletion behavior
                    cmp.confirm({ select = true })
                else
                    fallback()
                end
            end, { "i", "s" }),
        })
    end,
}
