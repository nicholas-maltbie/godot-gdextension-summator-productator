//© Copyright 2014-2022, Juan Linietsky, Ariel Manzur and the Godot community (CC-BY 3.0)
#include "productator.h"

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

Productator::Productator()
{
    prod = 1;
}

Productator::~Productator()
{
}

void Productator::mul(int p_value)
{
    prod *= p_value;
}

void Productator::reset()
{
    prod = 1;
}

int Productator::get_total() const
{
    return prod;
}

void Productator::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("mul", "value"), &Productator::mul, DEFVAL(1));
    ClassDB::bind_method(D_METHOD("reset"), &Productator::reset);
    ClassDB::bind_method(D_METHOD("get_total"), &Productator::get_total);
}