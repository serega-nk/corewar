.name    "zork"
.comment "just a basic living prog
asdasdasda sda
sdasdasdas"
		
l2: sati	r1,%:live,%0
	and	r1,%0,r1
live:	live	%1
	zjmp	%:live
