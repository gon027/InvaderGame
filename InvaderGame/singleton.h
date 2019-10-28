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
	//代入演算子禁止
	singleton& operator=(const singleton& obj) = delete;
	//コピーコンストラクタ禁止
	singleton(const singleton& obj) = delete;
};

#endif // !SINGLETON_H
