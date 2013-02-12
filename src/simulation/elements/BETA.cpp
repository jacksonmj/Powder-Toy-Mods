#include "simulation/Elements.h"
//#TPT-Directive ElementClass Element_BETA PT_BETA 173
Element_BETA::Element_BETA()
{
    Identifier = "DEFAULT_PT_BETA";
    Name = "BETA";
    Colour = PIXPACK(0x00FF00);
    MenuVisible = 1;
    MenuSection = SC_NUCLEAR;
    Enabled = 1;
    
    Advection = 0.0f;
    AirDrag = 0.00f * CFDS;
    AirLoss = 1.00f;
    Loss = 1.00f;
    Collision = -1.0f;
    Gravity = 0.0f;
    Diffusion = 0.01f;
    HotAir = 0.002f	* CFDS;
    Falldown = 0;
    
    Flammable = 0;
    Explosive = 0;
    Meltable = 0;
    Hardness = 0;
    
    Weight = -1;
    
    Temperature = R_TEMP+4.0f	+273.15f;
    HeatConduct = 60;
    Description = "Beta- Radiation, Produces Free Electrons While Going Through Air";
    
    State = ST_GAS;
    Properties = TYPE_GAS|PROP_LIFE_DEC|PROP_LIFE_KILL_DEC;
    
    LowPressure = IPL;
    LowPressureTransition = NT;
    HighPressure = IPH;
    HighPressureTransition = NT;
    LowTemperature = ITL;
    LowTemperatureTransition = NT;
    HighTemperature = ITH;
    HighTemperatureTransition = NT;
    Update = &Element_BETA::update;
    Graphics = &Element_BETA::graphics;
}

//#TPT-Directive ElementHeader Element_BETA static int update(UPDATE_FUNC_ARGS)
int Element_BETA::update(UPDATE_FUNC_ARGS)
{
	if (0.2>rand()%400)
        sim->create_part(i,x,y,PT_ELEC);
        return 0;
	
}

//#TPT-Directive ElementHeader Element_BETA static int graphics(GRAPHICS_FUNC_ARGS)
int Element_BETA::graphics(GRAPHICS_FUNC_ARGS)

{
	*firea = 120;
	*firer = 0;
	*fireg = 255;
	*fireb = 0;

	*pixel_mode |= FIRE_ADD;
	return 1;
}

Element_BETA::~Element_BETA() {}
