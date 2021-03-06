#ifndef MOJA_FLINT_EXAMPLE_AGRI_LANDUSEMODULE_H_
#define MOJA_FLINT_EXAMPLE_AGRI_LANDUSEMODULE_H_

#include "moja/_core_exports.h"
#include "moja/flint/imodule.h"
#include "moja/flint/modulebase.h"
#include <moja/flint/itiming.h>
#include "moja/flint/example/agri/_modules.agri_exports.h"
#include "moja/datarepository/iproviderrelationalinterface.h"

namespace moja {
namespace flint {
namespace example {
namespace agri {

class AGRI_API LandUseModule : public flint::ModuleBase
{
    std::string prevLandType, soilType, climateZone, climate;
    double prevSOC = -1, SOC_REF;

public:
	LandUseModule() = default;
	~LandUseModule() = default;

	void configure(const DynamicObject& config) override;
	void subscribe(NotificationCenter& notificationCenter) override;

	void onLocalDomainInit() override;
	void onTimingInit() override;
	void onTimingStep() override;

private:
	void InitializeForASimulation();
	void SubmitMoves();
	void ClassifyClimate();

	const flint::IPool* _soil;
    const flint::IPool* _atmosphere;
    const flint::IPool* _initialValues;

    const flint::IVariable* _change;
    const flint::IVariable* _climateZone;
    const flint::IVariable* _soilType;
    const flint::IVariable* _stockRef;
    const flint::IVariable* _changeFactor;
};

}  // namespace agri
}  // namespace example
}  // namespace flint
}  // namespace moja

#endif // MOJA_FLINT_EXAMPLE_AGRI_LANDUSEMODULE_H_
