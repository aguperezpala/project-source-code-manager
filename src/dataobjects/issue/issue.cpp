#include "issue.h"

Issue::Issue()
{
	// nothing
}

void Issue::getStringStatus(string &s)
{
	if (this->status == ISSUE_S_DONE)
		s = "DONE";
	else if (this->status == ISSUE_S_CHECKED)
		s = "CHECKED";
	else
		s = "UNKNOWN";
	
}
void Issue::getStringKind(string &type)
{
	if(this->kind == ISSUE_K_BUGFIX)
		type = "BUGFIX";
	else if(this->kind == ISSUE_K_REVISION)
		type = "REVISION";
	else if(this->kind == ISSUE_K_TODO)
		type = "TODO";
	else if(this->kind == ISSUE_k_IMPROVE)
		type = "IMPROVE";
	else if(this->kind == ISSUE_K_NORMAL)
		type = "NORMAL";
	else
		type = "UNKNOWN";
	
}
void Issue::getStringPriority(string &p)
{
	if(this->priority == ISSUE_P_LOW)
		p = "LOW";
	else if(this->priority == ISSUE_P_MEDIUM)
		p = "MEDIUM";
	else if(this->priority == ISSUE_P_HIGH)
		p = "HIGH";
	else
		p = "UNKNOWN";
}


/* setea/obtiene el tiempo de creacion */
void Issue::setCreatedTime(time_t &ct)
{
	memcpy(&this->createdTime, &ct, sizeof(ct));
}

/* setea/obtiene el tiempo de fecha limite */
void Issue::setLimitTime(time_t &lt)
{
	memcpy(&this->limitTime, &lt, sizeof(lt));
}



void Issue::Print(void)
{
	cout << "\nIssue desc: " << this->desc;
	cout << "\nIssue title: " << this->title;
	cout << "\nIssue status: " << this->status;
	cout << "\nIssue kind: " << this->kind;
	cout << "\nIssue priority: " << this->priority;
	
	
}
