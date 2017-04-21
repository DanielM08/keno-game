#include "kenobet.h"


	std::vector<int> spots = { 2, 5, 19, 21, 56, 78 };
	int NR = 5;
	float cash = 1500;

	kenobet ap;
	ap.set_wage( cash );
	ap.set_rounds( NR );

	for ( auto i(sports.begin()); i != spots.end(); i++ )
		ap.add_number( i );

	return ap;


int main()
{

	kenoGame game;

	auto ap = game.initialize_game( argv[1] );

	while( not game.game_over( ) )
	{
		game.process_events();
		game.update();
		game.render();
	}

	game.render();
}