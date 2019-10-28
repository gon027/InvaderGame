#ifndef SINGLETON_H
#define SINGLETON_H

template <class T>
class singleton {
public:
	static T& getInstance() {
		static T instance;
		return instance;
	}

protected:
	singleton() = default;
	virtual ~singleton() = default;

private:
	//������Z�q�֎~
	singleton& operator=(const singleton& obj) = delete;
	//�R�s�[�R���X�g���N�^�֎~
	singleton(const singleton& obj) = delete;
};

#endif // !SINGLETON_H
