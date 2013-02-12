#include "simulation/Elements.h"
//#TPT-Directive ElementClass Element_MRBR PT_MRBR 171
Element_MRBR::Element_MRBR()
{
    Identifier = "DEFAULT_PT_MRBR";
    Name = "MRBR";
    Colour = PIXPACK(0x999999);
    MenuVisible = 1;
    MenuSection = SC_LIQUID;
    Enabled = 1;
    
    Advection = 0.4f;
    AirDrag = 0.04f * CFDS;
    AirLoss = 0.94f;
    Loss = 0.95f;
    Collision = -0.1f;
    Gravity = 0.3f;
    Diffusion = 0.00f;
    HotAir = 0.000f	* CFDS;
    Falldown = 1;
    
    Flammable = 0;
    Explosive = 0;
    Meltable = 5;
    Hardness = 1;
   
	Weight = 23;
    
    Temperature = R_TEMP+0.0f	+273.15f;
    HeatConduct = 50;
    Description = "Liquid. Pressure sensitive explosive.";
    
    State = ST_LIQUID;
    Properties = TYPE_LIQUID;
    
    LowPressure = 0.0;
    LowPressureTransition = PT_MRBR;
    HighPressure = 256.0;
    HighPressureTransition = PT_MRBR;
    LowTemperature = 500;
    LowTemperatureTransition = PT_RBER;
    HighTemperature = 9999.0;
    HighTemperatureTransition = PT_MRBR;
    
    Update =  &Element_MRBR::update;

}
//#TPT-Directive ElementHeader Element_MRBR static int update(UPDATE_FUNC_ARGS)
int Element_MRBR::update(UPDATE_FUNC_ARGS)
{
        if (1>rand()%1000)
                sim->create_part(i,x,y,PT_SMKE);
        return 0;
}

Element_MRBR::~Element_MRBR() {}