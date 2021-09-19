all:
	g++ game_test.cpp FieldCage.cpp FieldCage.hpp Field.cpp Field.hpp Game.cpp Game.hpp -o app -lsfml-graphics -lsfml-window -lsfml-system
