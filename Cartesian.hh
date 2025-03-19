#pragma once
#include "Coordinate.hh"
#include <string>

class Cartesian : public Coordinate {
    public:
        Cartesian(double x, double y) : x_(x), y_(y) {}
        virtual std::string ToString() override;
        virtual double Distance(const Cartesian& coord) const;

    private:
        double x_;
        double y_;
};
