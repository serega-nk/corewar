.name "zork"
.comment "just a basic living prog"


aff r1
zjmp	%:live	
l2:	sti	r1,%:live,%0
	and	r1,%0,r1
live:
	aff r1
	live	%1
	
	zjmp	%:live
