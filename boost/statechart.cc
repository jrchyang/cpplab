#include <boost/statechart/state_machine.hpp>
#include <boost/statechart/simple_state.hpp>
#include <boost/statechart/transition.hpp>
#include <boost/mpl/list.hpp>
#include <iostream>

namespace sc = boost::statechart;

// 事件声明
struct Play : sc::event<Play> {};
struct Stop : sc::event<Stop> {};
struct Pause : sc::event<Pause> {};
struct EndPause : sc::event<EndPause> {};

// 前向状态声明
struct Stopped;
struct Playing;
struct Paused;

// 状态机
struct Player : sc::state_machine<Player, Stopped> {};

// Stopped 状态
struct Stopped : sc::simple_state<Stopped, Player>
{
	Stopped() { std::cout << "enter stopped state" << std::endl; }
	typedef sc::transition<Play, Playing> reactions;
};

// Playing 状态
struct Playing : sc::simple_state<Playing, Player>
{
	Playing() { std::cout << "enter playing state" << std::endl; }
	typedef boost::mpl::list<
		sc::transition<Stop, Stopped>,
		sc::transition<Pause, Paused> > reactions;
};

// Paused 状态
struct Paused : sc::simple_state<Paused, Player>
{
	Paused() { std::cout << "enter paused state" << std::endl; }
	typedef boost::mpl::list<
		sc::transition<EndPause, Playing>,
		sc::transition<Stop, Stopped> > reactions;
};

int main()
{
	Player myPlayer;
	myPlayer.initiate();

	myPlayer.process_event(Play());
	myPlayer.process_event(Pause());
	myPlayer.process_event(EndPause());
	myPlayer.process_event(Stop());

	return 0;
}
