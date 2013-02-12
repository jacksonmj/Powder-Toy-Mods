#include "simulation/Elements.h"
//#TPT-Directive ElementClass Element_ALPH PT_ALPH 172
Element_ALPH::Element_ALPH()
{
    Identifier = "DEFAULT_PT_ALPH";
    Name = "ALPH";
    Colour = PIXPACK(0x0000FF);
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
    Description = "Alpha Radiation, Produces Helium (Nble) After Losing Energy To Air";
    
    State = ST_GAS;
    Properties = TYPE_ENERGY|PROP_LIFE_DEC|PROP_LIFE_KILL_DEC;
    
    LowPressure = IPL;
    LowPressureTransition = NT;
    HighPressure = IPH;
    HighPressureTransition = NT;
    LowTemperature = ITL;
    LowTemperatureTransition = NT;
    HighTemperature = ITH;
    
	HighTemperatureTransition = NT;
    Update = &Element_ALPH::update;
    Graphics = &Element_ALPH::graphics;
}

//#TPT-Directive ElementHeader Element_ALPH static int update(UPDATE_FUNC_ARGS)
int Element_ALPH::update(UPDATE_FUNC_ARGS)
{
        if (0.2>rand()%100)
                sim->create_part(i,x,y,PT_NBLE);
        return 0;	
}
//#TPT-Directive ElementHeader Element_ALPH static int graphics(GRAPHICS_FUNC_ARGS)
int Element_ALPH::graphics(GRAPHICS_FUNC_ARGS)

{
	*firea = 120;
	*firer = 0;
	*fireg = 0;
	*fireb = 255;

	*pixel_mode |= FIRE_ADD;
	return 1;
}

Element_ALPH::~Element_ALPH() {}
