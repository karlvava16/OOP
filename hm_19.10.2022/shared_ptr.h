#pragma once

namespace my
{
	template <class T>
	class shared_ptr
	{
		T* ptr;
		static unsigned count;

	public:
		shared_ptr() : ptr(nullptr) {}
		shared_ptr(T* sh) : ptr(sh) { count++; }
		shared_ptr(const shared_ptr<T>& sh) : ptr(sh.ptr) { count++; }
		shared_ptr(shared_ptr<T>&& sh) : ptr(sh.ptr) {}

		shared_ptr& operator= (const shared_ptr<T>& obj)
		{
			if (this == &obj || obj.ptr == ptr)
				return*this;
			ptr = obj.ptr;
			count++;
			return*this;
		}

		shared_ptr& operator= (shared_ptr<T>&& obj)
		{
			if (this == &obj || obj.ptr == ptr)
				return*this;
			ptr = obj.ptr;
			return*this;
		}

		T* get()
		{
			return ptr;
		}

		unsigned use_count() const
		{
			return count;
		}

		~shared_ptr()
		{
			if (count == 1)
				delete[] ptr;
		}
	};

	template <class T>
	unsigned shared_ptr<T>::count = 0;
}