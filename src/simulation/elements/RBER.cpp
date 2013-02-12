#include "simulation/Elements.h"
#include "simulation/Air.h"
//#TPT-Directive ElementClass Element_RBER PT_RBER 170
Element_RBER::Element_RBER()
{

    Identifier = "DEFAULT_PT_RBER";
    Name = "RBER";
    Colour = PIXPACK(0x333333);
    MenuVisible = 1;
    MenuSection = SC_SPECIAL;
    Enabled = 1;
    
    Advection = 0.0f;
    AirDrag = 0.00f * CFDS;
    AirLoss = 0.95f;
    Loss = 0.00f;
    Collision = 0.0f;
    Gravity = 0.0f;
    Diffusion = 0.00f;
    HotAir = 0.000f	* CFDS;
    Falldown = 0;
    
    Flammable = 0;
    Explosive = 0;
    Meltable = 1;
    Hardness = 10;
    
    Weight = 100;
    
    Temperature = R_TEMP+0.0f	+273.15f;
    HeatConduct = 10;
    Description = "Rubber, insulates, protects, melts and smokes to the high hells.";
    
    State = ST_SOLID;
    Properties = TYPE_SOLID;
    
    LowPressure = IPL;
    LowPressureTransition = NT;
    HighPressure = IPH;
    HighPressureTransition = NT;
    LowTemperature = ITL;
    LowTemperatureTransition = NT;
    HighTemperature = 500.0f;
    HighTemperatureTransition = PT_MRBR;
    
    Update = &Element_TTAN::update; 
} 
//#TPT-Directive ElementHeader Element_RBER static int update(UPDATE_FUNC_ARGS)
int Element_RBER::update(UPDATE_FUNC_ARGS)
 {
	int nx, ny, rber = 0;
	if(nt<=2)
		rber = 2;
	else if(parts[i].tmp)
		rber = 2;
	else if(nt<=6)
		for (nx=-1; nx<2; nx++) {
			for (ny=-1; ny<2; ny++) {
				if ((!nx != !ny) && x+nx>=0 && y+ny>=0 && x+nx<XRES && y+ny<YRES) {
					if((pmap[y+ny][x+nx]&0xFF)==PT_RBER)
						rber++;
				}
			}
		}

	if(rber>=2) {
		sim->air->bmap_blockair[y/CELL][x/CELL] = 1;
		sim->air->bmap_blockairh[y/CELL][x/CELL] = 1;
	}
	return 0;
}



Element_RBER::~Element_RBER() {}