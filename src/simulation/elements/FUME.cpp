#include "simulation/Elements.h"
//#TPT-Directive ElementClass Element_FUME PT_FUME 168
Element_FUME::Element_FUME()
{
    Identifier = "DEFAULT_PT_FUME";
    Name = "FUME";
    Colour = PIXPACK(0x666666);
    MenuVisible = 1;
    MenuSection = SC_GAS;
    Enabled = 1;
    
    Advection = 1.0f;
    AirDrag = 0.01f * CFDS;
    AirLoss = 0.99f;
    Loss = 0.30f;
    Collision = -0.1f;
    Gravity = 0.999f;
    Diffusion = 0.1f;
    HotAir = 0.0f	* CFDS;
    Falldown = 0;
    
    Flammable = 900;
    Explosive = 0;
    Meltable = 0;
    Hardness = 1;
    
    Weight = 0.01;
    
    Temperature = R_TEMP+2.0f	+273.15f;
    HeatConduct = 42;
    Description = "Liquid Gas Vapor";
    
    State = ST_GAS;
    Properties = TYPE_GAS;
    
    LowPressure = IPL;
    LowPressureTransition = NT;
    HighPressure = 6.0f;
    HighPressureTransition = PT_LGAS;
    LowTemperature = ITL;
    LowTemperatureTransition = NT;
    HighTemperature = 573.0f;
    HighTemperatureTransition = PT_FIRE;
    
    Update = NULL;
    
}

Element_FUME::~Element_FUME() {}