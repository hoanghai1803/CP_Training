" User Interface
syntax on                 " Enable highlight syntax 
set nu                    " Show line number
set ruler                 " Show cursor position in bottom line
set cursorline            " Highlight cursor line
set title                 " Set the window’s title
set mouse=a               " Enable mouse
set showmatch             " Highlight matching [{()}]

" Theme config
" Need to install vim-polyglot to improve highlight syntax
let g:onedark_terminal_italics=1
let g:onedark_termcolors=256
colorscheme onedark       " Set colorscheme to onedark.vim

" Setting for tab 
set tabstop=4             " Set tab width to 4 columns 
set softtabstop=4         " Set soft tab stop to 4
set expandtab             " Convert tabs to spaces
set shiftwidth=4          " Tab size = 4 spaces
set autoindent            " New lines inherit the indentation of previous lines
set smarttab              " Insert “tabstop” number of spaces when the “tab” key is pressed
set shiftround            " When shifting non-aligned set of lines, align them to next tabstop

" Searching
set hlsearch  	          " Enable seach highlighting
set incsearch             " Show first match when start typing
set ignorecase            " Ignore case when searching 
set smartcase             " Use case sensitive if I use uppercase

" Text Rendering 
set encoding=utf-8        " Use an encoding that supports unicode.
set scrolloff=10          " Do not let cursor scroll below or above 10 number of lines when scrolling
set nowrap                " Do not wrap lines. Allow long lines to extend as far as the line goes

" File Handling
set autoread              " Reload files if changed externally

" Add useful stuff to title bar (file name, flags, cwd)
if has('title') && (has('gui_running') || &title)
    set titlestring=
    set titlestring+=%f
    set titlestring+=%h%m%r%w
    set titlestring+=\ -\ %{v:progname}
    set titlestring+=\ -\ %{substitute(getcwd(),\ $HOME,\ '~',\ '')}
endif

" Auto closing brackets
inoremap " ""<left>
inoremap ' ''<left>
inoremap ( ()<left>
inoremap [ []<left>
inoremap { {}<left>
inoremap {<CR> {<CR>}<ESC>O
inoremap {;<CR> {<CR>};<ESC>O

" Map keys 
:vmap <C-C> "+y	

" Quickly comment line
function! MyComment()
  let l = getline('.')
  if l =~ '^\s*\/\/'
    let l = substitute(l, '\/\/ ', '', '')
  else
    let l = '// ' . l
  endif
  call setline(line('.'), l)
endfunction
nnoremap <C-k> :call MyComment()<CR>

" Auto commands
autocmd BufNewFile *.cpp 0r ~/.vim/templates/skeleton.cpp