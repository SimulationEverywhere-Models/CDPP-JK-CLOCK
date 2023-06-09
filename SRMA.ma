[top]
components : SR

out : Q Q_bar
in : S R

Link : S S@SR
Link : R R@SR
Link : Q_bar@SR Q_bar
Link : Q@SR Q

[SR]
components : nor_A@norGate nor_B@norGate

out : Q Q_bar
in : S R

Link : S in_a@nor_A
Link : R in_b@nor_B
Link : out@nor_A Q_bar
Link : out@nor_B Q
Link : out@nor_A in_a@nor_B
Link : out@nor_B in_b@nor_A

[nor_A]
delay : 00:00:00:03

[nor_B]
delay : 00:00:00:03 
