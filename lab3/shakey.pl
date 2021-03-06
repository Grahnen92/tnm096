% shakey World

% actions
act( move_from_rx_to_ry(X,Y),
     [room(X), room(Y), connected(X,Y), in(X, shakey)],
     [in(X, shakey)],
     [in(Y, shakey)]
     ).
     
act( light_on(X, Y),
     [room(X), switch(Y), in(X,Y), in(X, shakey), off(Y)],
     [off(Y)],
     [on(Y)]
     ).
     
act( light_off(X, Y),
     [room(X), switch(Y), in(X,Y), in(X, shakey), on(Y)],
     [on(Y)],
     [off(Y)]
     ).
act( pick_up_box(X, Y),
     [room(X), box(Y), in(X,Y), in(X, shakey), notheld(Y), handempty],
     [notheld(Y), handempty, in(X,Y) ],
     [held(Y) ]
     ).
act( drop_box(X, Y),
     [room(X), box(Y), in(X,Y), in(X, shakey), held(Y), in(shakey, Y)],
     [held(Y)],
     [notheld(Y), handempty, in(X,Y)]
     ).


%goal_state( [ in(r1, shakey) ]).
%goal_state( [ off(s1)]).
goal_state( [ in(r2, b2)]).

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
            box(b5),  %remove
            
            switch(s1),
            switch(s2),
            switch(s3),
            switch(s4),
            
            robot(shakey),
            
            door(d1),
            door(d2),
            door(d3),
            door(d4),
            
            %contents of room 1
            in(r1, b1),
            in(r1, b2),
            in(r1, b3),
            in(r1, b4),
            in(r1, s1),
            %contents of room 2
            in(r2, s2),
            %contents of room 3
            in(r3, s3),
            in(r3, shakey),
            %contents of room 4
            in(r4, s4),
            %room connections
            connected(r1, c),
            connected(r2, c),
            connected(r3, c),
            connected(r4, c),
            
            connected(c, r1),
            connected(c, r2),
            connected(c, r3),
            connected(c, r4),
            %box status
            notheld(b1),
            notheld(b2),
            notheld(b3),
            notheld(b4),
            handempty,
            held(b5),
            %light switch status
            on(s1),
            on(s4),
            off(s2),
            off(s3)
     ]).
