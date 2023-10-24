"Disabling some command to increase security
set secure

"Disable the basic vim without vimrc
unlet! skip_defaults_vim

"Show the line number
set number

"Put at coloumn 81 al line to know where is 81 char limit
set colorcolumn=81

"Choose the color of the column
highlight ColorColumn ctermbg=7

"Not highlighting when searching a pattern in the page
noh

"Choose the size of a tab
set tabstop=4

"Choose the color
color everforest

"Choose the color of the background
set	background=dark


syntax on

"Youss ? for the 
set list

"Youss ? permet de display (-->) et ~ sur espace
set listchars=tab:>-,trail:~

"Set the maxium supported color of the term
set t_Co=256

"Set the highlight for specialkey the color 240
highlight SpecialKey ctermfg=240

packloadall

call plug#begin()

" post install (yarn install | npm install) then load plugin only for editing supported files
Plug 'prettier/vim-prettier', {
  \ 'do': 'npm install',
  \ 'for': ['javascript', 'typescript', 'css', 'less', 'scss', 'json', 'graphql', 'markdown', 'vue', 'svelte', 'yaml', 'html'] }

" Max line length that prettier will wrap on: a number or 'auto' (use
" textwidth).
" default: 'auto'
let g:prettier#config#print_width = 'auto'

" number of spaces per indentation level: a number or 'auto' (use
" softtabstop)
" default: 'auto'
let g:prettier#config#tab_width = 'auto'

" use tabs instead of spaces: true, false, or auto (use the expandtab setting).
" default: 'auto'
let g:prettier#config#use_tabs = 'auto'

" flow|babylon|typescript|css|less|scss|json|graphql|markdown or empty string
" (let prettier choose).
" default: ''
let g:prettier#config#parser = ''

" cli-override|file-override|prefer-file
" default: 'file-override'
let g:prettier#config#config_precedence = 'file-override'

" always|never|preserve
" default: 'preserve'
let g:prettier#config#prose_wrap = 'preserve'

" css|strict|ignore
" default: 'css'
let g:prettier#config#html_whitespace_sensitivity = 'css'

" false|true
" default: 'false'
let g:prettier#config#require_pragma = 'false'

" Define the flavor of line endings
" lf|crlf|cr|all
" defaut: 'lf'
let g:prettier#config#end_of_line = get(g:, 'prettier#config#end_of_line', 'lf')
Plug 'preservim/nerdtree'
call plug#end()
