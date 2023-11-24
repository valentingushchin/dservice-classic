
#ifndef __DSERVICE_H__
#define __DSERVICE_H__

#include <wtypes.h>

#include "ComponentBase.h"
#include "AddInDefBase.h"
#include "IMemoryManager.h"

class DService : public IComponentBase
{
public:
    enum Props
    {
        eLastProperties
    };

    enum Methods
    {
        eVersion = 0,
        eLastMethod
    };

    DService(void);
    virtual ~DService();

    // IInitDoneBase
    virtual bool ADDIN_API Init(void*);
    virtual bool ADDIN_API setMemManager(void* mem);
    virtual long ADDIN_API GetInfo();
    virtual void ADDIN_API Done();

    // ILanguageExtenderBase
    virtual bool ADDIN_API RegisterExtensionAs(WCHAR_T** wsLanguageExt);
    virtual long ADDIN_API GetNProps();
    virtual long ADDIN_API FindProp(const WCHAR_T* wsPropName);
    virtual const WCHAR_T* ADDIN_API GetPropName(long lPropNum, long lPropAlias);
    virtual bool ADDIN_API GetPropVal(const long lPropNum, tVariant* pvarPropVal);
    virtual bool ADDIN_API SetPropVal(const long lPropNum, tVariant* varPropVal);
    virtual bool ADDIN_API IsPropReadable(const long lPropNum);
    virtual bool ADDIN_API IsPropWritable(const long lPropNum);
    virtual long ADDIN_API GetNMethods();
    virtual long ADDIN_API FindMethod(const WCHAR_T* wsMethodName);
    virtual const WCHAR_T* ADDIN_API GetMethodName(const long lMethodNum, const long lMethodAlias);
    virtual long ADDIN_API GetNParams(const long lMethodNum);
    virtual bool ADDIN_API GetParamDefValue(const long lMethodNum, const long lParamNum, tVariant *pvarParamDefValue);
    virtual bool ADDIN_API HasRetVal(const long lMethodNum);
    virtual bool ADDIN_API CallAsProc(const long lMethodNum, tVariant* paParams, const long lSizeArray);
    virtual bool ADDIN_API CallAsFunc(const long lMethodNum, tVariant* pvarRetValue, tVariant* paParams, const long lSizeArray);
    operator IComponentBase*() noexcept { return this; }

    // LocaleBase
    virtual void ADDIN_API SetLocale(const WCHAR_T* loc);
    virtual void ADDIN_API SetUserInterfaceLanguageCode(const WCHAR_T* lang);

private:
    long findName(const wchar_t* names[], const wchar_t* name, const uint32_t size) const;

    // Attributes
    std::u16string m_userLang;

    IAddInDefBase* m_iConnect;
    IMemoryManager* m_iMemory;
};

#endif //__DSERVICE_H__
