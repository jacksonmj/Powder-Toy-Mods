#include "simulation/Elements.h"
//#TPT-Directive ElementClass Element_LGAS PT_LGAS 167
Element_LGAS::Element_LGAS()
{

   Identifier = "DEFAULT_PT_LGAS";
    Name = "LGAS";
    Colour = PIXPACK(0xFFFF33);
    MenuVisible = 1;
    MenuSection = SC_LIQUID;
    Enabled = 1;
   
    Advection = 1.0f;
    AirDrag = 0.01f * CFDS;
    AirLoss = 0.98f;
    Loss = 0.95f;
    Collision = 0.0f;
    Gravity = 0.1f;
    Diffusion = 0.0f;
    HotAir = 0.0f       * CFDS;
    Falldown = 2;
   
    Flammable = 20;
    Explosive = 0;
    Meltable = 0;
    Hardness = 5;
   
    Weight = 15;
   
    Temperature = R_TEMP+0.0f   +273.15f;
    HeatConduct = 42;
    Description = "Liquid gas. You might find this in a car.";
   
    State = ST_LIQUID;
    Properties = TYPE_LIQUID;
   
    LowPressure = IPL;
    LowPressureTransition = NT;
    HighPressure = 30.0;
    HighPressureTransition = PT_FIRE;
    LowTemperature = ITL;
    LowTemperatureTransition = NT;
    HighTemperature = 393.0;
    HighTemperatureTransition = PT_FIRE;
 
    Update =  &Element_LGAS::update;

}
//#TPT-Directive ElementHeader Element_LGAS static int update(UPDATE_FUNC_ARGS)
int Element_LGAS::update(UPDATE_FUNC_ARGS)
{
        if (1>rand()%1000)
                sim->create_part(i,x,y,PT_FUME);
        return 0;
}
 
Element_LGAS::~Element_LGAS() {}
