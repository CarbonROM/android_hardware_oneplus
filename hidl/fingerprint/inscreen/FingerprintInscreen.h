/*
 * Copyright (C) 2021-2022 The LineageOS Project
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include <vendor/lineage/biometrics/fingerprint/inscreen/1.0/IFingerprintInscreen.h>
#include <vendor/oneplus/fingerprint/extension/1.0/IVendorFingerprintExtensions.h>
#include <vendor/oneplus/hardware/display/1.0/IOneplusDisplay.h>

namespace vendor {
namespace lineage {
namespace biometrics {
namespace fingerprint {
namespace inscreen {
namespace V1_0 {
namespace implementation {

using ::android::sp;
using ::android::hardware::Return;
using ::android::hardware::Void;
using ::vendor::oneplus::fingerprint::extension::V1_0::IVendorFingerprintExtensions;
using ::vendor::oneplus::hardware::display::V1_0::IOneplusDisplay;

class FingerprintInscreen : public IFingerprintInscreen {
  public:
    FingerprintInscreen();

    Return<void> onStartEnroll() override;
    Return<void> onFinishEnroll() override;
    Return<void> onPress() override;
    Return<void> onRelease() override;
    Return<void> onShowFODView() override;
    Return<void> onHideFODView() override;
    Return<bool> handleAcquired(int32_t acquiredInfo, int32_t vendorCode) override;
    Return<bool> handleError(int32_t error, int32_t vendorCode) override;
    Return<void> setLongPressEnabled(bool enabled) override;
    Return<int32_t> getDimAmount(int32_t cur_brightness) override;
    Return<bool> shouldBoostBrightness() override;
    Return<void> setCallback(const sp<IFingerprintInscreenCallback>& callback) override;
    Return<int32_t> getPositionX() override;
    Return<int32_t> getPositionY() override;
    Return<int32_t> getSize() override;

  private:
    bool mFodCircleVisible;

    sp<IOneplusDisplay> mVendorDisplayService;
    sp<IVendorFingerprintExtensions> mVendorFpService;

    std::mutex mCallbackLock;
    sp<IFingerprintInscreenCallback> mCallback;
};

}  // namespace implementation
}  // namespace V1_0
}  // namespace inscreen
}  // namespace fingerprint
}  // namespace biometrics
}  // namespace lineage
}  // namespace vendor
