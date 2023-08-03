# tiny-k

a tiny, incomplete k interpreter influenced by the j "incunabulum"[0]. over many summer afternoons...

this project was intended as fun challenge to see how much functionality could be crammed into a couple pages of code. some loose aims were:

- written in compact "Whitney-C" style (see [0])
- implement one dyadic arithmetic verb
- implement over and scan adverbs
- interpreter is memory safe (errors handled, no segfaults)
- compilable with gcc & clang with pedantic error flags
- script length 100 lines

the final script is a little longer than 100 lines, but otherwise I'm happy with the result. what's provided is a very restrictive subset of k. nonetheless, it has been useful for a few small problems. 

i intend to expand the code to a more conventionally readable format and add bytecode compilation and vm. this may serve as basic demo for k interpretation, a la Marc Feeley's tiny C program[1]. 

[0] https://code.jsoftware.com/wiki/Essays/Incunabulum

[1] https://www.iro.umontreal.ca/~felipe/IFT2030-Automne2002/Complements/tinyc.c
