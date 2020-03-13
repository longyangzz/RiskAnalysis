#include "DataType.h"

Database::Database()
	: QObject()
	, m_aqxs_threshold(2.5)
	, m_fx_threshold(25)
{

}

Database::~Database()
{

}

int Database::GetFieldNum()
{
	return m_fields.size();
}

FieldMap& Database::GetFields()
{
	return m_fields;
}

float Database::GetAQXSthreshold()
{
	return m_aqxs_threshold;
}

float Database::GetFXthreshold()
{
	return m_fx_threshold;
}

void Database::SetAQXSthreshold(float value)
{
	m_aqxs_threshold = value;
}
	
void Database::SetFXthreshold(float value)
{
	m_fx_threshold = value;
}


//! 根据传入的一行值和表头，计算输出个累加风险值
float Database::CalcFXvalue(QStringList headers, QStringList curLine)
{
	return 20;
}

//! 根据出入的风险值和安全系数值，计算输出个风险等级值
int Database::ClacFXLEVELvalue(float fxValue, float aqxsValue)
{
	//  |      0     |      1     
	//  ----------------------------（fx轴→）
	//  |      2     |      3
	//(aqxs轴↑)
	
	float fxthreshold = this->GetFXthreshold();
	float aqxsthreshold = this->GetAQXSthreshold();
	if(fxValue <= fxthreshold && aqxsValue > aqxsthreshold)
	{
		return 0;
	}

	if(fxValue > fxthreshold && aqxsValue > aqxsthreshold)
	{
		return 1;
	}

	if(fxValue > fxthreshold && aqxsValue <= aqxsthreshold)
	{
		return 3;
	}

	if(fxValue <= fxthreshold && aqxsValue <= aqxsthreshold)
	{
		return 2;
	}

	return 0;
}

//*****************************************************************
DatabaseParams::DatabaseParams()
	: QObject()
{

}

DatabaseParams::~DatabaseParams()
{

}
