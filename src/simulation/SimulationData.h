/*
 * SimulationData.h
 *
 *  Created on: Jan 24, 2012
 *      Author: Simon
 */

#define SC_WALL 0
#define SC_ELEC 1
#define SC_POWERED 2
#define SC_FORCE 3
#define SC_EXPLOSIVE 4
#define SC_GAS 5
#define SC_LIQUID 6
#define SC_POWDERS 7
#define SC_SOLIDS 8
#define SC_NUCLEAR 9
#define SC_SPECIAL 10
#define SC_LIFE 11
#define SC_TOOL 12
#define SC_DECO 13
#define SC_CRACKER 14
#define SC_CRACKER2 15
#define SC_TOTAL 14

#define UI_WALLSTART 222
#define UI_ACTUALSTART 122
#define UI_WALLCOUNT 25

#define WL_WALLELEC	122
#define WL_EWALL	123
#define WL_DETECT	124
#define WL_STREAM	125
#define WL_SIGN	126
#define WL_FAN	127
#define WL_FANHELPER 255
#define WL_ALLOWLIQUID	128
#define WL_DESTROYALL	129
#define WL_ERASE	130
#define WL_WALL	131
#define WL_ALLOWAIR	132
#define WL_ALLOWSOLID	133
#define WL_ALLOWALLELEC	134
#define WL_EHOLE	135

#define SPC_AIR 236
#define SPC_HEAT 237
#define SPC_COOL 238
#define SPC_VACUUM 239
#define SPC_WIND 241
#define SPC_PGRV 243
#define SPC_NGRV 244
#define SPC_PROP 246

#define WL_ALLOWGAS	140
#define WL_GRAV		142
#define WL_ALLOWENERGY 145

#define DECO_DRAW	0
#define DECO_ADD	1
#define DECO_SUBTRACT	2
#define DECO_MULTIPLY	3
#define DECO_DIVIDE	4

//Old IDs for GOL types
#define GT_GOL 78
#define GT_HLIF 79
#define GT_ASIM 80
#define GT_2x2 81
#define GT_DANI 82
#define GT_AMOE 83
#define GT_MOVE 84
#define GT_PGOL 85
#define GT_DMOE 86
#define GT_34 87
#define GT_LLIF 88
#define GT_STAN 89
#define GT_SEED 134
#define GT_MAZE 135
#define GT_COAG 136
#define GT_WALL 137
#define GT_GNAR 138
#define GT_REPL 139
#define GT_MYST 140
#define GT_LOTE 142
#define GT_FRG2 143
#define GT_STAR 144
#define GT_FROG 145
#define GT_BRAN 146

//New IDs for GOL types
#define NGT_GOL 0
#define NGT_HLIF 1
#define NGT_ASIM 2
#define NGT_2x2 3
#define NGT_DANI 4
#define NGT_AMOE 5
#define NGT_MOVE 6
#define NGT_PGOL 7
#define NGT_DMOE 8
#define NGT_34 9
#define NGT_LLIF 10
#define NGT_STAN 11
#define NGT_SEED 12
#define NGT_MAZE 13
#define NGT_COAG 14
#define NGT_WALL 15
#define NGT_GNAR 16
#define NGT_REPL 17
#define NGT_MYST 18
#define NGT_LOTE 19
#define NGT_FRG2 20
#define NGT_STAR 21
#define NGT_FROG 22
#define NGT_BRAN 23

#ifndef SIMULATIONDATA_H_
#define SIMULATIONDATA_H_

#include "Simulation.h"

/*class Simulation;
class Renderer;
struct Particle;*/

struct part_type;

struct part_transition;

struct wall_type;

struct gol_menu;

struct menu_section;

struct wall_type;

gol_menu * LoadGOLMenu(int & golMenuCount);

int * LoadGOLTypes(int & golTypeCount);

int * LoadGOLRules(int & golRuleCount);

wall_type * LoadWalls(int & wallCount);

menu_section * LoadMenus(int & menuCount);

part_type * LoadElements(int & elementCount);

part_transition * LoadTransitions(int & transitionCount);

#endif /* SIMULATIONDATA_H_ */