[top]
components : SR and_A@andGate and_B@andGate

out : Q Q_bar
in : J K enable

Link : J in_a@and_A
Link : enable in_enable@and_A
Link : k in_b@and_B
Link : enable in_enable@and_B
Link : Q_bar@SR Q_bar
Link : Q@SR Q
Link : Q_bar@SR in_b@and_A
Link : Q@SR in_a@and_B
Link : out@and_A S@SR
Link : out@and_B R@SR

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
delay : ""

[nor_B]
delay : "" 

[and_A]
delay : ""

[and_B]
delay : "" 
