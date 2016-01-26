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
- usage: ./shuffle -rev filename
- usage: ./shuffle -hex filename

- usage: ./shuffle -sh  filename
- usage: ./shuffle -ush filename
- usage: ./shuffle -add filename
- usage: ./shuffle -sub filename

- usage: ./shuffle -add number filename
- usage: ./shuffle -sub number filename

- usage: ./shuffle -sh  seed iterations filename
- usage: ./shuffle -ush seed iterations filename


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