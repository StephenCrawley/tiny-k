# tiny-k

a tiny, incomplete k interpreter influenced by the j incunabulum[0]. over many summer afternoons...

this project was intended as a fun challenge to see how much functionality could be crammed into a couple pages of code. some loose aims were:

- written in compact "Whitney-style" C (see [0])
- implement at least one dyadic arithmetic verb
- implement over and scan adverbs
- memory safe (errors handled, no segfaults, no memleaks)
- script length 100 lines

i tried to make the source compatible with -pedantic flag, but statement expressions were too enticing. the final script is a little longer than 100 lines, but otherwise i'm happy with the result. what's provided is a small but illustrative subset of k. 

i intend to expand the code to a more conventional C style and add bytecode compilation and a vm. this may serve as a basic demo for k interpretation, a la Marc Feeley's tiny C program[1]. 

[0] https://code.jsoftware.com/wiki/Essays/Incunabulum

[1] https://www.iro.umontreal.ca/~felipe/IFT2030-Automne2002/Complements/tinyc.c
