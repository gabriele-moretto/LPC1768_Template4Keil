#include "music.h"

#define UPTICKS 1


const NOTE tetris_theme[] =
{
	// Intro / Main theme
	{ e4, time_semiminima },
	{ b3, time_croma },
	{ c4, time_croma },
	{ d4, time_semiminima },
	{ c4, time_croma },
	{ b3, time_croma },

	{ a3, time_semiminima },
	{ a3, time_croma },
	{ c4, time_croma },
	{ e4, time_semiminima },
	{ d4, time_croma },
	{ c4, time_croma },

	{ b3, time_semiminima },
	{ b3, time_croma },
	{ c4, time_croma },
	{ d4, time_semiminima },
	{ e4, time_semiminima },

	{ c4, time_semiminima },
	{ a3, time_semiminima },
	{ a3, time_semiminima },
	{ pause, time_semiminima },

	// Second phrase
	{ d4, time_semiminima },
	{ f4, time_croma },
	{ a4, time_semiminima },
	{ g4, time_croma },
	{ f4, time_croma },

	{ e4, time_semiminima },
	{ e4, time_croma },
	{ c4, time_croma },
	{ e4, time_semiminima },
	{ d4, time_croma },
	{ c4, time_croma },

	{ b3, time_semiminima },
	{ b3, time_croma },
	{ c4, time_croma },
	{ d4, time_semiminima },
	{ e4, time_semiminima },

	{ c4, time_semiminima },
	{ a3, time_semiminima },
	{ a3, time_semiminima },
	{ pause, time_semiminima }
};

/******************************************************************************
**                            End Of File
******************************************************************************/
