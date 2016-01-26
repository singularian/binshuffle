# binshuffle
A Program to Shuffle Binary Files

This program is a commandline utility for Binary file shuffling. 
It allows the contents of a file to be reversibly reversibly shuffled and reversibly unshuffled.
The shuffle uses a pseudo random number generator to shuffle and unshuffle the file.
There are currently 8 file shuffle operations. It can also display the hex code of a file.
These are:
 
- 1) File reverse - Reverses a file
- 2) File shuffle - Randomly shuffles a file. This is reversible by the unshuffle.
- 3) File unshuffle - Unshuffle a file (This reverses a shuffle if the seed and iterations are the same)
- 4) Add to the file a random number
- 5) Subtract from the file (It is the reverse of an add)
- 6) Byte add - Add to the file bytes a number
- 6) Byte subtract - Subtract from file bytes a number 
- 7) Shuffle n iterations by a seed randomly
- 8) Unshuffle n iterations by a seed randomly


# Usage

This is the file command line usage. This program is written in C and can 
be compiled under Linux.

Shuffle arguments 1
- usage: ./shuffle -rev filename (Reverse a file)
- usage: ./shuffle -hex filename

- usage: ./shuffle -sh  filename (Shuffle a file)
- usage: ./shuffle -ush filename
- usage: ./shuffle -add filename
- usage: ./shuffle -sub filename

- usage: ./shuffle -add number filename
- usage: ./shuffle -sub number filename

- usage: ./shuffle -sh  seed iterations filename
- usage: ./shuffle -ush seed iterations filename

# Examples

These are some Linux command line examples of reversing and shuffling

./shuffle -rev data1.txt

./shuffle -rev data1.txt.reverse

./shuffle -rev data1.txt.reverse

./shuffle.sh -sh data1.txt

./shuffle -sh data1.txt

./shuffle -ush data1.txt.shuffle

./shuffle -add data1.txt

./shuffle -sub data1.txt.add

./shuffle -add data1.txt.shuffle.unshuffle

# Output

-rw-rw-r--.  1 data data        89 Jan 25 23:00 data1.txt
drwx------. 22 data data      4096 Jan 25 23:00 ..
-rw-rw-r--.  1 data data        89 Jan 25 23:04 data1.txt.reverse
-rw-rw-r--.  1 data data        89 Jan 25 23:04 data1.txt.reverse.reverse
-rw-rw-r--.  1 data data        89 Jan 25 23:05 data1.txt.shuffle
-rw-rw-r--.  1 data data        89 Jan 25 23:05 data1.txt.shuffle.unshuffle
-rw-rw-r--.  1 data data        89 Jan 25 23:05 data1.txt.add
-rw-rw-r--.  1 data data        89 Jan 25 23:06 data1.txt.add.sub
-rw-rw-r--.  1 data data        89 Jan 25 23:06 data1.txt.shuffle.unshuffle.add


# Donations

Bitcoin donations: 148JgizuinHxfPrAqtwJSZndPnnQcnHv4X


# Errata

# License

This program is licensed under the GNU GPL.

=============================================
Copyright 2016 Nathan Ross  

A Nathan Ross design
"Festival of a Thousand Lights"

January 29, 2014