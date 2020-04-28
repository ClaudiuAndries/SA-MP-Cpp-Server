#pragma once

class KeyStatement : public Singleton<KeyStatement>
{
public:
	void Execute(std::shared_ptr<Player> Player, int key);
private:

};