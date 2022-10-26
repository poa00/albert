// Copyright (c) 2022 Manuel Schneider

#pragma once
#include <QString>
#include <QObject>
#include <map>
#include "extension.h"

namespace albert
{
class App : public QObject
{
    Q_OBJECT

    struct Private;
    std::unique_ptr<Private> d;
    friend class SettingsWindow;

public:
    App(const QStringList &additional_plugin_dirs);
    void show(const QString &text);
    void showSettings();
    void restart();
    void quit();
//    void sendTrayNotification(const QString &title, const QString &message, const QIcon &icon) override;
//    albert::Terminal &terminal() override;
//    albert::ExtensionRegistry &extensionRegistry() override;

    App *instance();

    // Extension system

    void registerExtension(Extension *e);  /// Add extension to the registry
    void unregisterExtension(Extension *e);  /// Remove extension from the registry
    const std::map<QString,Extension*> &extensions();  /// Get all registered extensions

    /// Get a particular extension by its identifier with implicit cast
    template<typename T> T* extension(const QString &id) {
        try {
            return dynamic_cast<T*>(extensions().at(id));
        } catch (const std::out_of_range &) {
            return nullptr;
        }
    }

    /// Get all registered extensions of a particular type
    template<typename T> std::map<QString, T*> extensionsOfType() {
        std::map<QString, T*> results;
        for (const auto &[id, extension] : extensions())
            if (T *t = dynamic_cast<T*>(extension))
                results.emplace(id, t);
        return results;
    }

signals:
    void extensionRegistered(albert::Extension*);
    void extensionUnregistered(albert::Extension*);

};
//#define app albert::App::instance()
}