#include "Drawable.h"
#include "GraphicsThrowMacros.h"
#include "IndexBuffer.h"
#include <cassert>
#include <typeinfo>

void Drawable::Draw( Graphics& gfx ) const noexcept(!IS_DEBUG)
{
	uint32_t count = 0;

	for( auto& b : binds )
	{
	/*	if (const auto p = dynamic_cast<IndexBuffer*>(b.get()))
		{
			count = p->GetCount();
		}	*/
		b->Bind( gfx );
	}
	for (auto& b : GetStaticBinds())
	{
		if (const auto p = dynamic_cast<IndexBuffer*>(b.get()))
		{
			count = p->GetCount();
		}

		b->Bind(gfx);
	}
	gfx.DrawIndexed( count );
}

void Drawable::AddBind( std::unique_ptr<Bindable> bind ) noexcept(!IS_DEBUG)
{
	binds.push_back( std::move( bind ) );
}
