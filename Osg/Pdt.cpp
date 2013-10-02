#if defined(WIN32)
#include <windows.h>
#endif
#include "Classes/DefaultSetup.h"

int main() {
    Node *hand = osgDB::readNodeFile("../Captures/generated/300 poses/poses 100.0001.obj");
    PositionAttitudeTransform *transform = new PositionAttitudeTransform;
    transform->setAttitude(Vec4(-1, 0, 0, 1));
    transform->addChild(hand);

    PdtState state("../Captures/generated/300 poses fine", hand);
    fmat joints;
    joints << 1 << 0 << 0 << 0 << 1 << 0 << 0 << 0 << 1 << 0 << 0 << 0 << 1 << 0 << 0 << 0 << 1 << 0 << 0 << 0 << 1 << 0 << 0 << 0 << 1 << 0 << 0 << 0 << 1 << 0 << 0 << 0 << 1 << 0 << 0 << 0 << 1 << 0 << 0 << 0 << 1 << 0 << 0 << 0 << 1 << 0 << 0 << 0 << 1 << 0 << 0 << 0 << 1 << 0 << 0 << 0 << 1 << 0 << 0 << 0 << 1 << 0 << 0 << 0;
    joints = joints.t();
    state.updatePose(joints);
    
    return DefaultSetup(transform, state);
}