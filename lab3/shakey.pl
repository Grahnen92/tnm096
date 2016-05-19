% shakey World

% actions
act( move_from_rx_to_ry(X,Y),
     [room(X), room(Y), connected(X,Y), in(X, shakey)],
     [in(X, shakey)],
     [in(Y, shakey)]
     ).


goal_state( [ in(r1, shakey) ]).
%goal_state( [ Off(s1)]).
%goal_state( [ In(r2, b2)]).

initial_state(
     [      room(r1),
            room(r2),
            room(r3),
            room(r4),
            room(c),
            
            box(b1),
            box(b2),
            box(b3),
            box(b4),
            
            switch(s1),
            switch(s2),
            switch(s3),
            switch(s4),
            
            robot(shakey),
            
            door(d1),
            door(d2),
            door(d3),
            door(d4),
            
            in(r1, b1),
            in(r1, b2),
            in(r1, b3),
            in(r1, b4),
            in(r1, s1),

            in(r2, s2),
            
            in(r3, s3),
            in(r3, shakey),
            
            in(r4, s4),
            
            connected(r1, c),
            connected(r2, c),
            connected(r3, c),
            connected(r4, c),
            
            connected(c, r1),
            connected(c, r2),
            connected(c, r3),
            connected(c, r4),
            
            on(s1),
            on(s4),
            off(s2),
            off(s3)
     ]).
