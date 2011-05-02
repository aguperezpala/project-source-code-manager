#include "Issue.h"

void Issue::getStringStatus(std::string &s) const
{
	if (mStatus == ISSUE_S_DONE)
		s = "DONE";
	else if (mStatus == ISSUE_S_CHECKED)
		s = "CHECKED";
	else
		s = "UNKNOWN";
	
}
void Issue::getStringKind(std::string &type) const
{
	if(mKind == ISSUE_K_BUGFIX)
		type = "BUGFIX";
	else if(mKind == ISSUE_K_REVISION)
		type = "REVISION";
	else if(mKind == ISSUE_K_TODO)
		type = "TODO";
	else if(mKind == ISSUE_k_IMPROVE)
		type = "IMPROVE";
	else if(mKind == ISSUE_K_NORMAL)
		type = "NORMAL";
	else
		type = "UNKNOWN";
	
}
void Issue::getStringPriority(std::string &p) const
{
	if(mPriority == ISSUE_P_LOW)
		p = "LOW";
	else if(mPriority == ISSUE_P_MEDIUM)
		p = "MEDIUM";
	else if(mPriority == ISSUE_P_HIGH)
		p = "HIGH";
	else
		p = "UNKNOWN";
}


/* setea/obtiene el tiempo de creacion */
void Issue::setCreatedTimeNow(void)
{
	mCreatedTime = time(0);
}
void Issue::setCreatedTime(const time_t &ct)
{
	std::memcpy(&mCreatedTime, &ct, sizeof(ct));
}

/* setea/obtiene el tiempo de fecha limite */
void Issue::setLimitTime(const time_t &lt)
{
	std::memcpy(&mLimitTime, &lt, sizeof(lt));
}



void Issue::Print(void)
{
	cout << "\nIssue desc: " << mDesc;
	cout << "\nIssue title: " << mTitle;
	cout << "\nIssue status: " << mStatus;
	cout << "\nIssue kind: " << mKind;
	cout << "\nIssue priority: " << mPriority;
	
	
}
