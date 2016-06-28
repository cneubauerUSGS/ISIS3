#ifndef ProjectItem_h
#define ProjectItem_h
/**
 * @file
 * $Date$
 * $Revision$
 *
 *   Unless noted otherwise, the portions of Isis written by the USGS are
 *   public domain. See individual third-party library and package descriptions
 *   for intellectual property information, user agreements, and related
 *   information.
 *
 *   Although Isis has been used by the USGS, no warranty, expressed or
 *   implied, is made by the USGS as to the accuracy and functioning of such
 *   software and related material nor shall the fact of distribution
 *   constitute any such warranty, and no responsibility is assumed by the
 *   USGS in connection therewith.
 *
 *   For additional information, launch
 *   $ISISROOT/doc//documents/Disclaimers/Disclaimers.html
 *   in a browser or see the Privacy &amp; Disclaimers page on the Isis website,
 *   http://isis.astrogeology.usgs.gov, and the USGS privacy and disclaimers on
 *   http://www.usgs.gov/privacy.html.
 */


#include <QStandardItem>

#include "BundleSettings.h"
#include "GuiCamera.h"
#include "TargetBody.h"

namespace Isis {
  
  class BundleResults;
  class BundleSolutionInfo;
  class Control;
  class ControlList;
  class CorrelationMatrix;
  class Image;
  class ImageList;
  class GuiCameraList;
  class Project;
  class ProjectItemModel;
  class TargetBodyList;

  /**
   * Represents an item of a ProjectItemModel in Qt's model-view
   * framework.  Items are stored in a tree structure. A ProjectItem
   * directly stores the Data it corresponds to as well as other
   * display information.
   *
   * A ProjectItem may have a parent item and children items. An item
   * can add another item as a child using the appendRow() or
   * insertRow() methods on the parent item. Top level items in the
   * model should be added using the corresponding methods in the
   * model. If an item already has a parent or is already added to a
   * model, it must be removed from the parent using the takeChild()
   * method on the old parent item, or the takeItem() method on the
   * model, before it is added to a new parent or model.
   *
   * A ProjectItem stores text, an icon, and data. These values can be
   * set using the setText(), setIcon(), and setData() methods. The
   * data must be converted to a QVariant before being stored using
   * setData(). There are various convinence methods for setting and
   * accessing data. For example, the setImage() method will set the
   * text, icon, and data appropriately given an Image. Also, the
   * image() method will return the Image if one is stored in the
   * data, or a null pointer if one is not.
   *
   * ProjectItem does not inherit from QObject. The model associated
   * with the ProjectItem should be used to utilize signals and
   * slots. When a ProjectItem is deleted it deletes all of its
   * children. Top level items are deleted by the model associated
   * with them. To delete an item manually it must first be removed
   * from its parent item or its model with the takeItem() method.
   *
   * Any type of data that can be converted to a QVariant can be
   * stored in a ProjectItem. If the ProjectItem cannot store the data
   * it represents directly, then the data() method can be overridden
   * in a subclass to access the data where it is stored.
   *
   * Item selections are handled by the model associated with the item.
   *
   * @code
   * Image *image = new Image("example.cub");
   * ProjectItemModel *model = new ProjectItemModel();
   * ProjectItem *item = new ProjectItem(project);
   * model->appendRow(item);
   * @endcode
   *
   * @internal
   *   @author Jeffrey Covington
   *
   *     @history 2015-10-21 Jeffrey Covington - Original version.
   *     @history 2016-06-27 Ian Humphrey - Minor documentation updates. Fixes #4006.
   */
  class ProjectItem : public QStandardItem {
    public:
      ProjectItem();
      explicit ProjectItem(ProjectItem *item);
      ProjectItem(BundleResults bundleResults);
      ProjectItem(BundleSettingsQsp bundleSettings);
      ProjectItem(BundleSolutionInfo *bundleSolutionInfo);
      ProjectItem(Control *control);
      ProjectItem(ControlList *controlList);
      ProjectItem(QList<ControlList *> controls);
      ProjectItem(CorrelationMatrix correlationMatrix);
      ProjectItem(Image *image);
      ProjectItem(ImageList *imageList);
      ProjectItem(QList<ImageList *> images);
      ProjectItem(GuiCameraQsp guiCamera);
      ProjectItem(GuiCameraList *guiCameraList);
      ProjectItem(Project *project);
      ProjectItem(QList<BundleSolutionInfo *> results);
      ProjectItem(TargetBodyQsp targetBody);
      ProjectItem(TargetBodyList *targetBodyList);

      ~ProjectItem();

      BundleResults bundleResults() const;
      BundleSettingsQsp bundleSettings() const;
      BundleSolutionInfo *bundleSolutionInfo() const;
      Control *control() const;
      ControlList *controlList() const;
      CorrelationMatrix correlationMatrix() const;
      Image *image() const;
      ImageList *imageList() const;
      Project *project() const;
      GuiCameraQsp guiCamera() const;
      TargetBodyQsp targetBody() const;

      bool isBundleResults() const;
      bool isBundleSettings() const;
      bool isBundleSolutionInfo() const;
      bool isControl() const;
      bool isControlList() const;
      bool isCorrelationMatrix() const;
      bool isImage() const;
      bool isImageList() const;
      bool isProject() const;
      bool isGuiCamera() const;
      bool isTargetBody() const;

      void setProjectItem(ProjectItem *item); 
      void setBundleResults(BundleResults bundleResults);
      void setBundleSettings(BundleSettingsQsp bundleSettings);
      void setBundleSolutionInfo(BundleSolutionInfo *bundleSolutionInfo);
      void setControl(Control *control);
      void setControlList(ControlList *controlList);
      void setControls();
      void setCorrelationMatrix(CorrelationMatrix correlationMatrix);
      void setImage(Image *image);
      void setImageList(ImageList *imageList);
      void setImages();
      void setProject(Project *project);
      void setResults();
      void setGuiCamera(GuiCameraQsp guiCamera);
      void setGuiCameraList();
      void setShapeModels();
      void setSpacecraft();
      void setTargetBody(TargetBodyQsp targetBody);
      void setTargetBodyList();

      ProjectItem *findItemData(const QVariant &value, int role = Qt::UserRole+1);
      
      void appendRow(ProjectItem *item);
      ProjectItem *child(int row) const;
      void insertRow(int row, ProjectItem *item);
      ProjectItemModel *model() const;
      ProjectItem *parent() const;
      void setChild(int row, ProjectItem *item);
      ProjectItem *takeChild(int row);
    };

}

Q_DECLARE_METATYPE(Isis::ProjectItem *);

#endif