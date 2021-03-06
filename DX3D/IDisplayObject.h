#pragma once
#include "BaseObject.h"

class IDisplayObject : public BaseObject
{
protected:
	D3DXVECTOR3				m_pos;
	D3DXVECTOR3				m_rot;
	D3DXMATRIXA16			m_matWorld;

	IDisplayObject*			m_pParent;
	vector<IDisplayObject*> m_vecPChild;

public:
	IDisplayObject();
	virtual ~IDisplayObject();

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
    virtual void Release() override;
	virtual void AddChild(IDisplayObject& val);

    D3DXVECTOR3		     GetPosition() const;
    void			     SetPosition(const D3DXVECTOR3& pos);
    D3DXVECTOR3		     GetRotation() const;
    const D3DXMATRIXA16& GetWorldMatrix() const;

	D3DXVECTOR3		GetPosition() { return m_pos; }
	void			SetPosition(D3DXVECTOR3* pos) { m_pos = *pos; }
	D3DXVECTOR3		GetRotation() { return m_rot; }
	D3DXMATRIXA16	GetWorldMatrix() { return m_matWorld; }
    ///////�߰��� �κ�
    const vector<IDisplayObject*>& GetChildVec() { return m_vecPChild; }

    void UpdateChildren();
    void RenderChildren();
    void ReleaseChildren();

};

