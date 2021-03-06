#include "stdafx.h"
#include "UIText.h"
#include "UIManager.h"

UIText::UIText()
    : UIObject()
    , m_pFont(nullptr)
    , m_drawTextFormat(DT_CENTER | DT_VCENTER)
{
}

UIText::~UIText()
{
}

void UIText::Render()
{
    if (!m_pFont) return;

	m_pFont->DrawText(g_pSprite, m_text, lstrlen(m_text), &m_rect, m_drawTextFormat, m_color);
	UIObject::Render();
}

void UIText::SetFont(const LPD3DXFONT val)
{
    m_pFont = val;
}

void UIText::SetText(const LPCTSTR val)
{
    m_text = val;
}

void UIText::SetDrawTextFormat(const DWORD val)
{
    m_drawTextFormat = val;
}
