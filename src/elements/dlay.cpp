#include "simulation/Element.h"

int update_DLAY(UPDATE_FUNC_ARGS) {
	int r, rx, ry, oldl;
	oldl = parts[i].life;
	if (parts[i].life>0)
		parts[i].life--;
	//if (parts[i].life==1)
	//{
	if (parts[i].temp>=MAX_TEMP+273.15f)
		parts[i].temp = MAX_TEMP+273.15f;
	if (parts[i].temp<= 1.0f+273.15f)
		parts[i].temp = 1.0f+273.15f;

		for (rx=-2; rx<3; rx++)
			for (ry=-2; ry<3; ry++)
				if (x+rx>=0 && y+ry>0 && x+rx<XRES && y+ry<YRES && (rx || ry))
				{
					r = pmap[y+ry][x+rx];
					if (!r || sim->parts_avg(r>>8, i,PT_INSL)==PT_INSL)
						continue;
					if ((r&0xFF)==PT_SPRK && parts[i].life==0 && parts[r>>8].life>0 && parts[r>>8].life<4 && parts[r>>8].ctype==PT_PSCN)
					{
						parts[i].life = (int)(parts[i].temp-273.15);
					}
					else if ((r&0xFF)==PT_DLAY)
					{
						if(!parts[i].life && parts[r>>8].life)
						{
							parts[i].life = parts[r>>8].life;
							if((r>>8)>i) //If the other particle hasn't been life updated
								parts[i].life--;
						}
						else if(parts[i].life && !parts[r>>8].life)
						{
							parts[r>>8].life = parts[i].life;
							if((r>>8)>i) //If the other particle hasn't been life updated
								parts[r>>8].life++;
						}
					}
					else if((r&0xFF)==PT_NSCN && oldl==1)
					{
						sim->create_part(-1, x+rx, y+ry, PT_SPRK);
					}
				}
	//}
	return 0;
}