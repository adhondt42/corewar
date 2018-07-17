.name "Simon"
.comment "This is a proto"



#start:		st		r2, 1
			ld		%0, r2

#life_zone:	live 	%0
#			sti		r1, %:life_zone, %1

##duplicate:	fork	%15

#loop:		zjmp	%:life_zone



#generator:		st		r2, 1
				#ld		%0, r2
generator:		fork	%6
				zjmp	%:generator



start:		st		r2, 1
			ld		%0, r2

core:		live 	%0
			sti		r1, %:core, %1

loop:		zjmp	%:core