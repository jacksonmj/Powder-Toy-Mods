#include "simulation/Elements.h"
//#TPT-Directive ElementClass Element_NTRG PT_NTRG 169
Element_NTRG::Element_NTRG()
{
    Identifier = "DEFAULT_PT_NTRG";
    Name = "NTRG";
    Colour = PIXPACK(0x66CCCC);
    MenuVisible = 1;
    MenuSection = SC_GAS;
    Enabled = 1;
    
    Advection = 1.0f;
    AirDrag = 0.01f * CFDS;
    AirLoss = 0.99f;
    Loss = 0.30f;
    Collision = -0.1f;
    Gravity = 0.0f;
    Diffusion = 0.75f;
    HotAir = 0.001f	* CFDS;
    Falldown = 0;
    
    Flammable = 0;
    Explosive = 0;
    Meltable = 0;
    Hardness = 1;
    
    Weight = 1;
    
    Temperature = R_TEMP-120.0f	+273.15f;
    HeatConduct = 42;
    Description = "Nitrogen Gas";
    
    State = ST_GAS;
    Properties = TYPE_GAS;
    
    LowPressure = IPL;
    LowPressureTransition = NT;
    HighPressure = 6.0f;
    HighPressureTransition = NT;
    LowTemperature = -30.0f;
    LowTemperatureTransition = PT_LNTG;
    HighTemperature = 9999.0f;
    HighTemperatureTransition = PT_PLSM;
    
    Update = NULL;
    
}

Element_NTRG::~Element_NTRG() {}