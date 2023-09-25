extends Node

func _ready():
	var p = Productator.new()
	p.mul(2)
	p.mul(3)
	p.mul(4)
	print("Productator: %s" % p.get_total())
	p.reset()
