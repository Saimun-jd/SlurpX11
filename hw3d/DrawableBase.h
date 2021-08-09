#pragma once
#include "Drawable.h"
#include "IndexBuffer.h"

template<typename T>
class DrawableBase : public Drawable
{
protected:
	static bool IsStaticInitialized() noexcept
	{
		return !staticBinds.empty();
	}
	static void AddStaticBind(std::unique_ptr<Bindable> bind) noexcept(!IS_DEBUG)
	{
		staticBinds.push_back(std::move(bind));
	}
private:
	const std::vector<std::unique_ptr<Bindable>>& GetStaticBinds() const noexcept override
	{
		return staticBinds;
	}
private:
	static std::vector<std::unique_ptr<Bindable>> staticBinds;
};

template<typename T>
std::vector<std::unique_ptr<Bindable>> DrawableBase<T>::staticBinds;
