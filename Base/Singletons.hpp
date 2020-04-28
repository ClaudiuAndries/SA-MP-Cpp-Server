#pragma once

template <class T>
class Singleton
{
public:
	inline static bool DeleteInstance()
	{
		if (s_data == nullptr)
		{
			return false;
		}
		delete s_data;
		s_data = 0;
		return true;
	}

	inline static T* GetInstance()
	{
		if (s_data == nullptr)
		{
			s_data = new T;
		}
		return s_data;
	}


private:
	static T* s_data;
};

template <typename T>
T* Singleton<T>::s_data;