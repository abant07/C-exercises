#pragma once
#include "Coordinate.hh"

class Polar: public Coordinate {
    public:
        Polar(double radius, double angle) : radius_(radius), angle_(angle) {}
        virtual std::string ToString() override;
        virtual double Distance(const Polar& coord) const;
    
    private:
        double radius_;
        double angle_;
};