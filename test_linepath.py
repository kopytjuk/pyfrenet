import pyfrenet

lp = pyfrenet.LinePath((0.0, 0.0), (10.0, 0.0))

print(lp)

assert lp.get_length() == 10.0

print(lp.to_frenet(0.0, 0.0))
