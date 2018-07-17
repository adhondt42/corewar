.name "proto"
.comment "proto"

cary:		ld %0, r2
			st r1, 6
deb:		live %:deb
			zjmp %:deb


