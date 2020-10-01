.name       "Chabrec_trava"
.comment    "Zavari menya detka!!!!!"

loop:
        sti r1, %:live, %1
live:
        fork %:live
        live %0
        ld %0, r2
        lfork %:loop
