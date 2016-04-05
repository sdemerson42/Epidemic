#ifndef __AUTOLIST__
#define __AUTOLIST__

#include <vector>

template<typename T>
class AutoList
{
public:
	AutoList()
	{
		m_ref.push_back(static_cast<T*>(this));
	}
	~AutoList()
	{
		for (int i = 0; i < m_ref.size(); ++i)
		{
			if (m_ref[i] == this)
			{
				m_ref.erase(m_ref.begin() + i);
				break;
			}
		}
	}
	static int size() { return m_ref.size(); }
	static T* get(int i) { return m_ref[i]; }
private:
	static std::vector<T*> m_ref;
};

template<typename T>
std::vector<T*> AutoList<T>::m_ref;

#endif