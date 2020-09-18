

/**************************************************************************************************
 *** This file was autogenerated from GrTrackedInUniform.fp; do not modify.
 **************************************************************************************************/
#include "GrTrackedInUniform.h"

#include "src/core/SkUtils.h"
#include "src/gpu/GrTexture.h"
#include "src/gpu/glsl/GrGLSLFragmentProcessor.h"
#include "src/gpu/glsl/GrGLSLFragmentShaderBuilder.h"
#include "src/gpu/glsl/GrGLSLProgramBuilder.h"
#include "src/sksl/SkSLCPP.h"
#include "src/sksl/SkSLUtil.h"
class GrGLSLTrackedInUniform : public GrGLSLFragmentProcessor {
public:
    GrGLSLTrackedInUniform() {}
    void emitCode(EmitArgs& args) override {
        GrGLSLFPFragmentBuilder* fragBuilder = args.fFragBuilder;
        const GrTrackedInUniform& _outer = args.fFp.cast<GrTrackedInUniform>();
        (void) _outer;
        auto color = _outer.color;
        (void) color;
        colorVar = args.fUniformHandler->addUniform(&_outer, kFragment_GrShaderFlag, kHalf4_GrSLType, "color");
        fragBuilder->codeAppendf(
R"SkSL(%s = %s;
)SkSL"
, args.fOutputColor, args.fUniformHandler->getUniformCStr(colorVar));
    }
private:
    void onSetData(const GrGLSLProgramDataManager& pdman, const GrFragmentProcessor& _proc) override {
        const GrTrackedInUniform& _outer = _proc.cast<GrTrackedInUniform>();
        {
        const SkRect& colorValue = _outer.color;
        if (colorPrev.isEmpty() || colorPrev != colorValue) {
            colorPrev = colorValue;
            pdman.set4fv(colorVar, 1, reinterpret_cast<const float*>(&colorValue));
        }
        }
    }
SkRect colorPrev = SkRect::MakeEmpty();
    UniformHandle colorVar;
};
GrGLSLFragmentProcessor* GrTrackedInUniform::onCreateGLSLInstance() const {
    return new GrGLSLTrackedInUniform();
}
void GrTrackedInUniform::onGetGLSLProcessorKey(const GrShaderCaps& caps, GrProcessorKeyBuilder* b) const {
}
bool GrTrackedInUniform::onIsEqual(const GrFragmentProcessor& other) const {
    const GrTrackedInUniform& that = other.cast<GrTrackedInUniform>();
    (void) that;
    if (color != that.color) return false;
    return true;
}
bool GrTrackedInUniform::usesExplicitReturn() const {
    return false;
}
GrTrackedInUniform::GrTrackedInUniform(const GrTrackedInUniform& src)
: INHERITED(kGrTrackedInUniform_ClassID, src.optimizationFlags())
, color(src.color) {
        this->cloneAndRegisterAllChildProcessors(src);
}
std::unique_ptr<GrFragmentProcessor> GrTrackedInUniform::clone() const {
    return std::make_unique<GrTrackedInUniform>(*this);
}
#if GR_TEST_UTILS
SkString GrTrackedInUniform::onDumpInfo() const {
    return SkStringPrintf("(color=half4(%f, %f, %f, %f))", color.left(), color.top(), color.right(), color.bottom());
}
#endif
