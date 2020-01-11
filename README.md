# fillit_v1

Fillit is a project that let you discover and/or familiarize yourself with a recurring problematic in programming: searching the optimal solution among a huge set of possibilities, in a respectable timing. In this particular project, you will have to find a way to assemble a given Tetriminos set altogether in the smallest possible square. A Tetriminos is a 4-blocks geometric figure you probably already heard of, thanks to the popular game Tetris

executable must take only one parameter, a file which contains a list of Tetriminos
to assemble. This file has a very specific format : every Tetrimino must exactly fit in a
4 by 4 chars square and all Tetrimino are separated by an newline each.
If the number of parameters sent to your executable is not 1, your program must display
its usage and exit properly. If you don’t know what a usage is, execute the command
cp without arguments in your Shell. It will give you an idea. Your file should contain
between 1 and 26 Tetriminos.

The description of a Tetriminos must respect the following rules :
• Precisely 4 lines of 4 characters, each followed by a new line (well... a 4x4 square).
• A Tetrimino is a classic piece of Tetris composed of 4 blocks.
• Each character must be either a block character(’#’ ) or an empty character (’.’).
• Each block of a Tetrimino must touch at least one other block on any of his 4 sides (up, down, left and right).
